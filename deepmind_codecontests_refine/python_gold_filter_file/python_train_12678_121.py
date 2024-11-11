N, A, B = map(int, input().split())
p = N//(A+B)
print(p*A+min(N%(A+B), A))