a = int(input())
p = list(map(int,input().split()))
count = 0

for i in range(a):
     for s in range(a):
         for t in range(a):
             if p[t]<p[s]<p[i] and p[t]+p[s]>p[i]:
                 count+=1
print(count)