N, A, B = map(int, input().split())
ans = N//(A+B)*A+min(N%(A+B),A)
print(ans)