S=list(input())
N=int(input())

i=0
while i<len(S)-1:
    if S[i]!='a' and 123-ord(S[i])<=N:
        N-=123-ord(S[i])
        S[i]='a'
    i+=1

N=N%26
while N:
    if S[-1]=='z':
        S[-1]='a'
    else:
        S[-1]=chr(ord(S[-1])+1)
    N-=1

print(''.join(S))
