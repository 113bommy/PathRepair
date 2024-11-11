params = [int(s) for s in input().split(" ")]
n = params[0]
k = params[1]
skills = [int(s) for s in input().split(" ")]
indexes_sorted= [b[0] for b in sorted(enumerate(skills),key=lambda i:i[1])]
bad_relations={}
for i in range(k):
    items = [int(s) for s in input().split(" ")]
    first = items[0] - 1
    second= items[1] - 1
    if skills[first] > skills[second]:
        bad_relations[first] = bad_relations.get(first, 0) + 1
    elif skills[second]> skills[first]:
        bad_relations[second] = bad_relations.get(second, 0) + 1

num_the_same=0
results = {}
prev=None
for idx, index in enumerate(indexes_sorted):
    skill = skills[index]
    if skill==prev:
        num_the_same+=1
    else:
        num_the_same=0
    cnt = idx - num_the_same - bad_relations.get(index,0)
    if cnt < 0:
        cnt= 0
    results[index]= cnt
    prev= skill
final=''
for i in range(n):
    final+=str((results[i])) + " "

print(final.strip())



