import sys
input = sys.stdin.readline

S=input().strip()
L=len(S)

ANS1=[0]*(L+10)
ANS2=[0]*(L+10)
ANS3=[0]*(L+10)

for i in range(L-2):
    if S[i]==S[i+1]==S[i+2]:
        ANS1[i]=1

for i in range(L-4):
    if S[i]==S[i+2]==S[i+4]:
        ANS2[i]=1

for i in range(L-6):
    if S[i]==S[i+3]==S[i+6]:
        ANS3[i]=1

SCORE=0

for i in range(L):
    if ANS1[i]==1:
        SCORE+=max(0,L-i-2)
    elif ANS1[i+1]==1:
        SCORE+=max(0,L-i-3)
    elif ANS1[i+2]==1:
        SCORE+=max(0,L-i-4)

    elif ANS2[i]==1:
        SCORE+=max(0,L-i-4)
    elif ANS2[i+1]==1:
        SCORE+=max(0,L-i-5)

        
    elif ANS1[i+3]==1:
        SCORE+=max(0,L-i-5)


        
        
    elif ANS1[i+4]==1:
        SCORE+=max(0,L-i-6)
    elif ANS2[i+2]==1:
        SCORE+=max(0,L-i-6)
    elif ANS3[i]==1:
        SCORE+=max(0,L-i-6)
        
    elif ANS1[i+5]==1:
        SCORE+=max(0,L-i-7)
    elif ANS2[i+3]==1:
        SCORE+=max(0,L-i-7)
    elif ANS3[i+1]==1:
        SCORE+=max(0,L-i-7)
     

    else:
        SCORE+=max(0,L-i-8)

    #print(SCORE)

print(SCORE)
        
        
