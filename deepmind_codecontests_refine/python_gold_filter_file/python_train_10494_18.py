N,A,B,C,D=map(int,input().split())
S=input()

if "##" in S[A:C-1] or "##" in S[B:D-1]:
    print("No")
    exit()
elif C > D and "..." not in S[B-2:D+1]:
    print("No")
else:
    print("Yes")
