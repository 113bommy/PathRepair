#!/usr/bin/env python
     
import sys
     
if __name__ == '__main__':
	wtf = sys.stdin.read()
	wtf = wtf.strip()
	wtf = wtf.split('\n')
	
	wtf = int(wtf[0])
	
	ans = []
	for i in range(wtf):
		if i % 2 == 0:
			ans.append('I hate')
		else:
			ans.append('I love')
		if i + 1 == wtf:
			ans.append('it')
		else:
			ans.append('that')

	print(' '.join(ans))