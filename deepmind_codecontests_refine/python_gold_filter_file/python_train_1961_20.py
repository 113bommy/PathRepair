X = int(input())
Y = list(map(int, str(X)))
if X >= 10:
  ans = max(sum(Y), Y[0]-1+9*(len(Y)-1))
else:
  ans = X
print(ans)
