n, p = map(int, input().split())
c = 0
st1 = []
st0 = []
fl = False
str_ = input()
for l in str_:
	if l == '.':
		if c - p >= 0 or c+p < n:
			if c-p>=0:
				delt = c-p
			else:
				delt = c+p
			t = str_[delt]
			if t == '0':
				str_ = list(str_)
				str_[c] = "1"
				str_ = "".join(str_).replace('.', "0")
				fl = True
				break
			elif t == '1':
				str_ = list(str_)
				str_[c] = "0"
				str_ = "".join(str_).replace('.', "0")
				fl = True
				break
			elif t == ".":
				str_ = list(str_)
				str_[c] = "1"
				str_[delt] = "0"
				str_ = "".join(str_).replace('.', "0")
				fl = True
				break
	if st1:
		if c == st1[0]:
			if l == "0":
				str_.replace(".", "0")
				fl = True
				break
			else:
				st1.pop(0)
	if st0:
		if c == st0[0]:
			if l == "1":
				str_.replace(".", "0")
				fl = True
				break
			else:
				st0.pop(0)
	if l == '0':
		st0.append(c+p)
	elif l == '1':
		st1.append(c+p)	
	c+=1
str_ = str_.replace('.', '0')
print(str_ if fl else "No")