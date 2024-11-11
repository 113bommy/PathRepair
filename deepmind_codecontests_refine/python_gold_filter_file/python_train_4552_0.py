""" 616C """
""" 1152B """
# import math
# import sys
def main():
	# n ,m= map(int,input().split())
	# arr = list(map(int,input().split()))
	# b = list(map(int,input().split()))
	# n = int(input())
	# TODO:
	# 1> LEETCODE FIRST PROBLEM WRITE
	n = int(input())
	arr = list(map(int,input().split()))
	add = sum(arr)
	if add/n>=4.5:
		print(0)
		return
	arr.sort()
	for i in range(n):
		add += 5-arr[i]
		# print(round((add/n)+0.1),add)
		if add/n>=4.5:
			print(i+1)
			return
		
main()
# def test():
# 	t = int(input())
# 	while t:
# 		main()
# 		t-=1
# test()
