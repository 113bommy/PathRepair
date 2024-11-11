n, k = map(int, input().split())
a = list(input().split())
for i in range(n, 10**6):
  if all([j not in a for j in str(i)]):
 #   print([j for j in str(i)])
    print(i)
    exit()