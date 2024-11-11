n = int(input())
a = list(map(int, input().split()))
k = max(a)
s = 0
s1 = 0
for i in range(n):
  s+=a[i]
  s1+=k-a[i]
d = 0
if s1<s:
 d =(s-s1)//n + min(1, (s-s1)%n)
if (s1+n*d)==s:
  d+=1
k+=d
print(k)