n=int(input())
s=input()
cnt_0=0
cnt_1=0
for i in range(n):
    if s[i]=='1':
        cnt_1+=1
    elif s[i]=='0':
        cnt_0+=1

c=min(cnt_0,cnt_1)
print(n-(2*c))
        