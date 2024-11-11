n = int( input() )
a_str = input()

a = a_str.split()
for i in range(n):
  a[i] = int( a[i] )


for i in range(n//2):
	if i%2 == 0 :
		temp = a[i]
		a[i] = a[n-i-1]
		a[n-i-1] = temp

for i in a:
  print(i, end = ' ')
  
#print('\b\n')