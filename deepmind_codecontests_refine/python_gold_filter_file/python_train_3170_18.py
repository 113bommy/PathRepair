#in the name of god
#Mr_Rubik
#''.join(sorted(a)) sort string
n=int(input())
s1,s2=input(),""
cnt1,cnt2=1,0
for i in range(1,n):
    s=input()
    if s==s1: cnt1+=1
    else:
        s2=s
        cnt2+=1
if cnt1>cnt2: print(s1)
else: print(s2)
