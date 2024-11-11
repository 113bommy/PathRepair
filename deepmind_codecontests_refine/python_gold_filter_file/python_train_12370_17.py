
N=int(input())
S=""
for i in range(50):
    if N%(-2)==0:
        S="0"+S
    else:
        S="1"+S
        N-=1
    N=N//(-2)
print(int(S))