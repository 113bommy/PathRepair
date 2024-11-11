N,A,B,C,D=map(int,input().split())
S=input()
if C<D:
    if "##" not in S[A-1:D]:
        print("Yes")
    else:
        print("No")
elif D<C:
    if "##" not in S[A-1:C] and "..." in S[B-2:D+1]:
        print("Yes")
    else:
        print("No")