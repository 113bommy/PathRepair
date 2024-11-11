n = int(input())
ar = input().split()
mi = ar.index(min(ar)) 
print("-1" if (n == 2 and ar[0] == ar[1]) or n<2 else "1 \r" + str(mi+1))