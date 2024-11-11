n = int(input())
aa = list(map(int,input().split()))
x = 0
for a in aa:
  x^=a
print(" ".join([str(x^a) for a in aa ]))