X=list(map(int , input().split()))
print("YES" if ((X[4] * abs(X[0] - X[2])) + (X[4] * abs(X[0]-X[1]) + (3 * X[5]))) <= (X[3] * abs(X[0] - X[1])) else "NO")
