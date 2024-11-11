N, A, B, C, D = map(int, input().split())
S = input()

if "##" in S[B: D - 1]:
    print("No")
    exit()
elif "##" in S[A: C - 1]:
    print("No")
    exit()

if D < C:
    if not "..." in S[B - 2: D + 1]:
        print("No")
        exit()

print("Yes")