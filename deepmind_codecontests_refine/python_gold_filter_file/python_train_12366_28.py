def add(in1, in2):
    return [a + b for a, b in zip(in1, in2)]
 
def split(ar, k, w):
    a = 0
    if max(max(ar)) > k:
      return -1
    tm = ar[0]
    for i in range(1, w):
        tm = add(tm, ar[i])
        if max(tm) > k:
            a += 1
            tm = ar[i]
    return a        
 
h, w, k = map(int, input().split())
s = [[int(i) for i in input()] for j in range(h)]
ans = h*w
 
for i in range(2**(h-1)):
    data = []
    temp = s[0]
    sp = bin(i+2**h)[4:]
    if ans < sp.count("1"):
        continue
    for j in range(1, h):
        if sp[j-1] == "0":
            temp = add(temp, s[j])
        else:
            data.append(temp)
            temp = s[j]
    data.append(temp)
    ans_ = split([list(x) for x in zip(*data)], k, w)
    if ans_ == -1:
        continue
    ans_ += sp.count("1")
    if ans > ans_:
        ans = ans_
print(ans)
