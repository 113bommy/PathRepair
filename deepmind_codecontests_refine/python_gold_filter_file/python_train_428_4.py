t=int(input())
for _ in range(t):
         n=int(input())
         s=input()
         ans1=n
         ans2=n
         for i in range(n):
                  if(s[i]=='>'):
                           ans1=i
                           break
         for i in range(n):
                  if(s[i]=='<'):
                           ans2=n-i-1
         print(min(ans1,ans2))