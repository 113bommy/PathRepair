'''4 2
10 4 10 15
1 2
4 3
'''

class Proger:
  def __init__(self, skill, proger_id):
    self.skill = skill
    self.proger_id = proger_id

  def __repr__(self):
    return '{id}: {skill}'.format(id=self.proger_id, skill=self.skill)

from collections import defaultdict

def main():
  _, k = map(int, input().strip().split(' '))
  progers = []
  argues = defaultdict(int)
  counter = 1
  
  for skill in input().strip().split(' '):
    sk = int(skill)
    progers.append(Proger(sk, counter))
    counter += 1


  skills_sorted = sorted(
    progers, 
    key=lambda proger: proger.skill
  )

  for _ in range(k):
    p1, p2 = map(int, input().strip().split(' '))
    if progers[p1 - 1].skill > progers[p2 - 1].skill:
      argues[p1] += 1
    
    if progers[p2 - 1].skill > progers[p1 - 1].skill:
      argues[p2] += 1

  # print('Argues', argues)

  padawan_counter = defaultdict(int)
  for idx in range(1, len(skills_sorted)):
    proger = skills_sorted[idx]
    prev_proger = skills_sorted[idx - 1]
    if prev_proger.skill < proger.skill:
      padawan_counter[proger.skill] = idx

  # print('Padawans', padawan_counter)

  res = []
  for proger in progers:
    res.append(padawan_counter[proger.skill] - argues[proger.proger_id])

  print(' '.join(str(count) for count in res))


if __name__ == '__main__':
  main()