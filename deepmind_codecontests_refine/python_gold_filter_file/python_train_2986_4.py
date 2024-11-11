from bisect import bisect

# Three displays
# 987 C

s = """5
2 4 5 4 10
40 30 20 10 40
"""

#s = """3
#100 101 100
#2 4 5"""
#
#s = """10
#1 2 3 4 5 6 7 8 9 10
#10 13 11 14 15 12 13 13 18 13
#"""
#
#s = """20
#452405440 586588704 509061481 552472140 16115810 148658854 66743034 628305150 677780684 519361360 208050516 401554301 954478790 346543678 387546138 832279893 641889899 80960260 717802881 588066499
#61699500 83254572 59454419 27833657 55743179 99661234 94729965 75591136 62937826 3626886 73906880 3664913 39990362 94385934 33153747 23840219 64514676 14746017 13062847 65187713
#"""

if False:
    def input(s=s.splitlines()):
        return s.pop(0)


n = int(input())
S = list(map(int, input().split()))
C = list(map(int, input().split()))

best = 10 ** 9

def one_size():
    best = [None] * n
    best[-1] = ([S[-1]], [C[-1]])  # two sorted lists of size and corresponding cost
    new_S, new_C = best[-1]
    for i in range(n-1)[::-1]:
        s = S[i]
        c = C[i]
        new_S = new_S[:]
        new_C = new_C[:]
        pos_s = bisect(new_S, s)
        pos_c = bisect(new_C, c)
        if pos_s >= pos_c:  # some smaller sizes have higher cost. They can be removed
            new_S[pos_c: pos_s] = [s]
            new_C[pos_c: pos_s] = [c]
        # if pos_s < pos_c, then there are larger sizes that don't have larger cost, so no need to insert this value
        best[i] = (new_S, new_C)
#    print(best)
    return best
        
   
def two_size(one_sizes):
    best = [None] * n
    best[-1] = [[], []]
    new_S, new_C = best[-1]
    for i in range(n-1)[::-1]:
        s = S[i]
        c = C[i]

        new_S = new_S[:]
        new_C = new_C[:]

        pos = bisect(one_sizes[i + 1][0], s)
        if pos < len(one_sizes[i + 1][1]):
            c += one_sizes[i + 1][1][pos]
            pos_s = bisect(new_S, s)
            pos_c = bisect(new_C, c)
            if pos_s >= pos_c:  # some smaller sizes have higher cost. They can be removed
                new_S[pos_c: pos_s] = [s]
                new_C[pos_c: pos_s] = [c]
            # if pos_s < pos_c, then there are larger sizes that don't have larger cost, so no need to insert this value
        best[i] = (new_S, new_C)
#    print(best)
    return best
            
if n > 1000 or 1:
    #n = 1000
    #S = S[:1000]
    #C = C[:1000]
    
    result = two_size(two_size(one_size()))

    if result[0] and result[0][1]:
        print(result[0][1][0])
    else:
        print(-1)
    #exit(0)

#def roll():
#    states1 = []
#    states2 = []
#    for s, c in zip(S, C):
#        for size, cost in states2:
#            if s > size:
#                yield cost + c
#        for size, cost in states1:
#            if s > size:
#                states2.append((s, cost + c))
#        states1.append((s, c))
#        states1 = [x for x in states1 if x[1] < best]
#        states2 = [x for x in states2 if x[1] < best]
#
#for c in roll():
##    print(c, best, end=", ")
#    if c < best:
#        best = c
#
#if best < 10 ** 9:
#    print(best)
#else:
#    print(-1)
##try:
##    print(*(roll()))
##except ValueError:
##    print(-1)