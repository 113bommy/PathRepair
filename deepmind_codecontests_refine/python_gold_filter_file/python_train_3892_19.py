#!/usr/bin/env python3 
import sys

if __name__ == "__main__":
	s = sys.stdin.readline()[:-1]
	c = sum(s.count(i)%2 for i in s)
	if c == 0 or c%2:
		print("First")
	else:
		print("Second")
	
