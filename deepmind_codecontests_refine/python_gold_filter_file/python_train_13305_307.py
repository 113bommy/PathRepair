A, B = map(int,input().split())
ans = A+B if B % A == 0 else B-A
print(ans)