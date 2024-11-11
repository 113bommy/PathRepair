def bin_search(array, element, lb, rb):
	l = list(array)
	
	s = list(element)
	
	n = len(l)
	
	left = int(lb)
	right = int(rb)
	
	while(left + 1 != right):
		mid = (right + left) // 2
		if s[0] > l[mid][0]:
			left = mid
		else:
			right = mid
			
		#print(left, ' ', right)
		
	return right
			
def list_insert(a, n, left, right):
	if n[0] >= a[right][0]:
		a.insert(right+1, n)
	else:
		if (n[0] <= a[left][0]):
			a.insert(left, n)
		else: 
			a.insert(bin_search(a, n, left, right), n)

def insertion_sort(array):
	l = list(array)
	
	n = len(l)
	
	for i in range(1, n):
		#print(l)
		val = l[i]
		l.pop(i)
		list_insert(l, val, 0, i-1)
		
	return l
		
def main():
	read = input().split()
	n = int(read[0])
	k = int(read[1])
	
	read = input().split()
	
	a = [[int(read[i]), i] for i in range(len(read))]
	
	a = insertion_sort(a)
	
	days = 0
	count = 0
	
	for i in range(len(a)):
		days += a[i][0]
		if days > k:
			break
		count += 1
		
	print(count)
	
	for i in range(count):
		print(a[i][1]+1, end = ' ')
		
		
	
	
	
main()
		
		
		