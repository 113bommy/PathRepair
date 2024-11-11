#coding:utf8

cnt_num = int(input())

a_str = input()
b_str = input()
a_arr = [int(x) for x in a_str.split(" ")]
b_arr = [int(x) for x in b_str.split(" ")]

if (a_arr[0] != b_arr[0]) or (a_arr[cnt_num - 1] != b_arr[cnt_num - 1]):
    print("No")
    exit(0)

a_tmp_arr, b_tmp_arr = [], []
for i in range(cnt_num - 1):
    a_tmp_arr.append(a_arr[i + 1] - a_arr[i])
    b_tmp_arr.append(b_arr[i + 1] - b_arr[i])

"""
if set(a_tmp_arr) != set(b_tmp_arr):
    print("No")
    exit(0)
else:
    print("Yes")
    exit(0)
"""

a_tmp_arr = sorted(a_tmp_arr)
b_tmp_arr = sorted(b_tmp_arr)

for i in range(cnt_num - 1):
    if a_tmp_arr[i] != b_tmp_arr[i]:
        print("No")
        exit(0)
print("Yes")
exit(0)


