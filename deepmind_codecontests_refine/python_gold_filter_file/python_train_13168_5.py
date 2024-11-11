from sys import argv
from collections import defaultdict
import sys

def convert(line):
	ret = []
	for e in line:
		try:
			ret.append(int(e))
		except:
			ret.append(e)
	return ret

def reader():
	for line in sys.stdin:
		yield convert(line.strip().split(' '))

def main():
	r = reader()
	n, m = next(r)
	
	sell = defaultdict(int)
	buy = defaultdict(int)
	for transaction, price, quantity in r:
		if transaction=='B':
			buy[price]+=quantity

		if transaction=='S':
			sell[price]+=quantity

	sell=sorted(sell.items(), key=lambda x:x[0], reverse=True)
	buy=sorted(buy.items(), key=lambda x:x[0], reverse=True)
	for p, q in sell[-m:]:
		print("S %d %d" % (p,q))

	for p, q in buy[:m]:
		print("B %d %d" % (p,q))

if __name__ == "__main__":
	main()
