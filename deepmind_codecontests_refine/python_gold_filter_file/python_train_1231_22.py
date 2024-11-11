N,H = map(int,input().split())
AB = [list(map(int,input().split())) for _ in range(N)]
A,B = zip(*AB)

a = max(A) #振る
B = [b for b in B if b > a] #投げる
B.sort(reverse = True)

answer = 0
hp = H
attack_cnt = 0

for b in B:
  if hp <= 0:
    break
  attack_cnt += 1
  hp -= b

if hp > 0:
  attack_cnt += (hp-1)//a + 1

print(attack_cnt)
