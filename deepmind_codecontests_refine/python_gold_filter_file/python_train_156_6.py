import sys
input=sys.stdin.readline
def main():
	n, k=map(int,input().split())
	id = list(map(int,input().split()))
	m = 0
	while(m*(m+1)<2*k):
		m+=1
	m-=1
	k -= m*(m+1)//2
	print(id[k-1])
main()
