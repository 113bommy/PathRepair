from sys import stdin

def main():
	n, x, y = [int(x) for x in stdin.readline().rstrip().split()]
	list1 = [int(x) for x in stdin.readline().rstrip().split()]
	
	list0 = [list1[0] +1] * x
	list2 = [list1[-1] + 1] * y
		
	mainlist=list0+list1+list2
	for i in range(x,len(mainlist)-y):
		if all(mainlist[i] < mainlist[x1] for x1 in range(i-x,i)) and all(mainlist[i] < mainlist[y1] for y1 in range(i+1,i+y+1)):
			return(i - x + 1)

print(main())