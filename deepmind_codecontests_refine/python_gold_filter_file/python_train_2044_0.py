n = int(input())

if n == 3:
    print(0)
    print(2, 1, 2)
    quit()

start = 1
if n % 2 != 0:
    start = 2

end = n // 2
if end % 2 != 0:
    end -= 1

a = [k for k in range(start, n + 1)]
b = a[::-1]

# print(a)
# print(b)

c = []
d = []
step = True

for k in range(end):
    if step:
        c.append(a[k])
        c.append(b[k])
    else:
        d.append(a[k])
        d.append(b[k])
    step = not step

if start != 1:
    c.insert(0, 1)

if end != n // 2:
    c.append(b[n // 2])
    d.append(a[n // 2])

print(abs(sum(c) - sum(d)))
print(len(c), *c)

# def var(s, c):
#     if c == 0:
#         for k in range(10):
#             s1 = str(s) + str(k)
#             print(s1)
#     else:
#         for k in range(10):
#             s1 = str(s) + str(k)
#             var(s1, c - 1)
#
#
# def var0():
#     for k in range(10):
#         var(k, 3)
#
#
# var0()
