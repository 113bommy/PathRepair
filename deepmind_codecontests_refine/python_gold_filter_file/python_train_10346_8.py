# coding=utf-8


if __name__ == '__main__':
	n, k = str(input()).split()
	n = int(n)
	k = int(k)
	tar = -999999999
	for i in range(n):
		f, t = str(input()).split()
		f = int(f)
		t = int(t)
		if t > k:
			tar = max(tar, f + k - t)
		else:
			tar = max(tar, f)
	print(tar)
