a = int(input())
s = input().split()
q = set()
lenght = 0
for i in range(1, a + 1):
    q.add(s[i*(-1)])
    if len(q) > lenght :
          k = s[i*(-1)]
    lenght = len(q)
print(k)
