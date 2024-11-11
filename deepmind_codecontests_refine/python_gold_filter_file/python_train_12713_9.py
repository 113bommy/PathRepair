n, k = map(int, input().split())

r_req = n * 2
g_req = n * 5
b_req = n * 8

if r_req % k == 0:
    no_r_books = r_req / k
else:
    no_r_books = (r_req //k) + 1

if g_req % k == 0:
    no_g_books = g_req / k
else:
    no_g_books = (g_req //k) + 1

if b_req % k == 0:
    no_b_books = b_req / k
else:
    no_b_books = (b_req //k) + 1

print(int(no_r_books + no_g_books + no_b_books))


#print(no_r_books)
#print(no_g_books)
#print(no_b_books)
