L = int(input())
node = 0
for i in range(21):
    if L < 2**i:
        L2 = 2**(i-1)
        N = i
        node = i - 1
        break

l = L - L2

L_reg = L2
L_tmp = L2
L_new = L2
L_bai = 1

a = []
b = []

def make_arr(init, N, a, b):
    global L_reg
    global L_tmp  # 各再帰計算時の値
    global L_new  # 単純なループ用
    global L_bai

    L_new = L_reg

    if [init, N] in a:
        # L_tmp = L_new
        L_tmp = L_new - L_bai
        L_bai *= 2
        # L_new += 1
        make_arr(init+1, N, a, b)
        a.remove([init, N])
        b.remove(max(b))
    else:
        a.append([init, N])
        b.append(L_new)
        L_reg += 1
        L_bai = 1


for i in range(l):
    make_arr(1,N,a,b)

for i in range(len(a)):
    a[i].append(b[i])

arr_0 = []
arr_2 = []

for i in range(node):
    arr_0.append([i + 1, i + 2, 0])
    arr_2.append([i + 1, i + 2, 2**i])

print(node+1,len(arr_0)+len(arr_2)+len(a))
for i in arr_0:
    print(i[0], i[1], i[2])
for i in arr_2:
    print(i[0], i[1], i[2])
for i in a:
    print(i[0], i[1], i[2])