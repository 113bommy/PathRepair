le = int(input())
n = sorted(map(int, input().split()))

# 1: faccio il sorting
n.sort()
# 2: abbasso tutti fino ad occupare lo spazio più vicino possibile al precedente (senza diventarne uguale)
# il primo ovviamente è 1 in ogni caso
n[0] = 1
for x in range(1,le):
	if n[x] > (n[x-1]+1):
		n[x] = n[x-1]+1

print (n[-1]+1)