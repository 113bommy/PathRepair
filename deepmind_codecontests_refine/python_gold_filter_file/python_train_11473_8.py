def criba_eratostenes(n):
  multiplos = set()
  for i in range(2, n+1):
    if i not in multiplos:
      multiplos.update(range(i*i, n+1, i))
      yield(i)
p = list(criba_eratostenes(10000))
for i in range(int(input())):
	a = [int(n) for n in input().split()]
	print('Infinite' if len([True for n in p if (a[0]/n==a[0]//n) and (a[1]/n==a[1]//n)]) else 'Finite')