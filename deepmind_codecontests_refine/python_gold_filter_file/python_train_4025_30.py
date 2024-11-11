ans2=99999999999999
t,m = map(int,input().split())
h,d,c,n = map(int,input().split())
a = h//n
if h%n>0:
    a+=1
ans1 = a*c

if t<20:

    m_left = 60-m
    t_left = 20-t
    t_left -= 1
    t_left = t_left * 60
    t_left += m_left
    t_left *= d
    h += t_left
    # print(h)
    b = h // n
    if h % n > 0:
        b += 1
    ans2 = b * c
    dis = ans2 * 0.2
    ans2 -= dis
else:
    ans2 = ans1- (ans1*0.2)



print(min(ans1,ans2))

