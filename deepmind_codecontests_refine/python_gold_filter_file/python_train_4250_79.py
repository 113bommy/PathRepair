A,B,K = map(int, input().split())
l = [x for x in range(1, 101) if A % x == 0 and B % x == 0]
print(l[-K])
