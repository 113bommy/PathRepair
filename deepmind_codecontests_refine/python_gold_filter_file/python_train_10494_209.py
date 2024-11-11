import sys
input=sys.stdin.readline

N,A,B,C,D = map(int, input().split())
S = input().strip()

if "##" in S[A:C] or "##" in S[B:D]:
    print("No")
    exit()

if D < C:
#    print(S[A:D])
    if "..." not in S[B-2:D+1]:
        print("No")
        exit()
print("Yes")
