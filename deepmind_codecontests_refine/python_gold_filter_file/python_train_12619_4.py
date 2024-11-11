import sys
input = sys.stdin.readline
hell=1000000007

def meowmeow321():
    n,q=map(int,input().split())
    cnt=0
    mark1 = [0]*(n+5)
    mark2 = [0]*(n+5)
    for i in range(q):
        r,c = map(int,input().split())
        if r==1:
            if mark1[c]:
                cnt-=mark2[c]
                cnt-=mark2[c+1]
                cnt-=mark2[c-1]
            else:
                cnt+=mark2[c]
                cnt+=mark2[c+1]
                cnt+=mark2[c-1]
            mark1[c]=1-mark1[c]
        else:
            if mark2[c]:
                cnt-=mark1[c]
                cnt-=mark1[c+1]
                cnt-=mark1[c-1]
            else:
                cnt+=mark1[c]
                cnt+=mark1[c+1]
                cnt+=mark1[c-1]
            mark2[c]=1-mark2[c]
        if cnt==0:
            print("Yes")
        else:
            print("No")
#t=int(input())
t=1
for i in range(t):
    meowmeow321()