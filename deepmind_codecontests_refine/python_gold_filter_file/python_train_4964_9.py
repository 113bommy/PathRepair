"""."""


def get_win(cakes_nr, step):
    """."""
    win = 0
    while True:
        if cakes_nr <= step:
            win += cakes_nr
            break
        win += step
        cakes_nr -= step
        cakes_nr -= cakes_nr // 10
    return win

#
# print(2 * get_win(999999999999999973, 39259424579862574))
# print(2 * get_win(999999999999999973, 39259424579862572))


cakes_nr = int(input())
l_op = 0
r_cl = cakes_nr

while r_cl - l_op > 1:
    m = (l_op + r_cl) // 2
    win = get_win(cakes_nr, m)
    if win >= (cakes_nr + 1) // 2:
        r_cl = m
    else:
        l_op = m

# curr_best = cakes_nr
# for i in range(-50_000, 50_001):
#     if r_cl - i <= 0 or r_cl - i > cakes_nr:
#         continue
#     win = get_win(cakes_nr, r_cl - i)
#     if win >= cakes_nr / 2:
#         curr_best = r_cl - i

print(r_cl)
