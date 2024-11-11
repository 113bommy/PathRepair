import sys

(n, m) = sys.stdin.readline().split(' ')
n = int(n)
m = int(m)
a1097 = 1000000007


def myread(s, i):
    j = i
    lens = len(s)
    while j < lens and s[j] != ' ':
        j += 1
    return (int(s[i:j]), j + 1)


table = {}
total = 1

for i in range(n):
    inp = sys.stdin.readline()
    si = 0
    input_len, si = myread(inp, si)
    while input_len > 0:
        ij, si = myread(inp, si)
        ij -= 1
        input_len -= 1
        if ij not in table:
            table[ij] = {}

        if i in table[ij]:
            table[ij][i] += 1
        else:
            table[ij][i] = 1

unused = m - len(table.keys())
# print (table)
current_index = list(table.keys())

list_len = len(current_index)
# import pdb
# pdb.set_trace()
cache = {}

for val in table.values():
    key = tuple(sorted(val.items()))
    if key in cache:
        count = (cache[key] + 1) % a1097
        cache[key] = count
        total *= count
        total = total % a1097
    else:
        cache[key] = 1

# while list_len > 1:
#     count = 1
#     j = 1
#     cur_el = table[current_index[0]]
#     while j < list_len:
#         if cur_el == table[current_index[j]]:
#             count += 1
#             total *= count
#             total = total%a1097
#             del current_index[j]
#             list_len -=1
#         else:
#             j+=1
#     if count==1:
#         del current_index[0]
#         list_len -= 1

for i in range(2, unused + 1):
    total = (total * (i % a1097)) % a1097

print(total)
