H,W,N=map(int,input().split())
Sr,Sc=map(int,input().split())
S=input()
T=input()

wr=Sc
wl=Sc
hu=Sr
hd=Sr


ans='YES'
for i in range(N):
    if S[i]=='R':
        wr+=1
    elif S[i]=='L':
        wl-=1
    elif S[i]=='U':
        hu-=1
    elif S[i]=='D':
        hd+=1
    if wr>W or wl<1 or hu<1 or hd>H:
        ans='NO'
        break

    if T[i]=='R':
        wl = min(W,wl+1)
    elif T[i]=='L':
        wr = max(1,wr-1)
    elif T[i]=='U':
        hd= max(1,hd-1)
    elif T[i]=='D':
        hu=min(H,hu+1)

print(ans)