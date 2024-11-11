n,k = map(int,input().split())
a = list(map(int,input().split()))
b = list(reversed(a))
s1 = sum(b[:k])
after = [[n-k,s1]]

for i in range(k,n-k):
   s1+=b[i]
   s1-=b[i-k]
   if s1>=after[-1][-1]:
      after.append([n-i-1,s1])

   else:
      after.append(after[-1])

after = after[::-1]

s2 = sum(a[:k])

mx = s2+after[0][1]
ansa = 0
ansb = after[0][0]
for i in range(k,n-k):
   s2+=a[i]
   s2-=a[i-k]

   if s2+after[i-k+1][1]>mx:
      mx = s2+after[i-k+1][1]
      ansa= i-k+1
      ansb = after[i-k+1][0]

print(ansa+1,ansb+1)