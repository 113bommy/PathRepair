s=[0 for _ in range(26)]
n=int(input())
room=input()
buy=0
for i in range(2*n-2):
    if i%2==0:
        s[ord(room[i])-ord('a')]+=1
    else:
        p=room[i].lower()
        p=ord(p)-ord('a')
        if s[p] :
            s[p]-=1
        else:
            buy+=1

print(buy)

