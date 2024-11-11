X, A, B = map(int, input().split())
print(["NO", "YES"][(A*10+B)%4==0])