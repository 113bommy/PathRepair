h,w,n=map(int,input().split())
sr,sc=map(lambda x:int(x)-1,input().split())
s=input()
t=input()
answ,ansh=[0,w-1],[0,h-1]
for i in range(n):
    if s[-i-1]=='R':
        answ[1]-=1
    if s[-i-1]=='L':
        answ[0]+=1
    if s[-i-1]=='D':
        ansh[1]-=1
    if s[-i-1]=='U':
        ansh[0]+=1
    if answ[0]>answ[1] or ansh[0]>ansh[1]:
        print('NO')
        exit()
    if i==n-1:
        break
    if t[-i-2]=='R':
        answ[0]=max(0,answ[0]-1)
    if t[-i-2]=='L':
        answ[1]=min(w-1,answ[1]+1)
    if t[-i-2]=='D':
        ansh[0]=max(0,ansh[0]-1)
    if t[-i-2]=='U':
        ansh[1]=min(h-1,ansh[1]+1)
if answ[0]<=sc<=answ[1] and ansh[0]<=sr<=ansh[1]:
    print('YES')
else:
    print('NO')