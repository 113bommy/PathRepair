# _ = input()
# a = list(map(int,input().split()))
# b = list(map(int,input().split()))
# if b[0] < b[1]:
#     pass
# else:
#     b[0], b[1] = b[1], b[0]

# # print(b)
# sum1 = sum2 = 0
# for i in range(int(_)):
# #     print(i)
#     if i >= b[0]-1 and i < b[1]-1:
#         sum1 += a[i]
# #         print(sum1)
#     else:
#         sum2 += a[i]
# print(min(sum1,sum2))

    
# a = int(input())
# b = int(input())
# ac = int(input())
# bc = int(input())
# t = int(input())
# m = 0
# if a*(ac-1) + b*(bc-1) >= t:
#     print('0', end=' ')
# else:
#     print(t-(a*(ac-1) + b*(bc-1)), end=' ')

# if ac < bc:
#     pass
# else:
#     ac, bc = bc, ac
#     a, b = b, a

# if ac*a < t:
#     m = a
#     t = t-ac*a
#     m += t//bc
# else:
#     m = t//ac
# print(m)

def fact(n):
    f = 1
    for i in range(2,n+1):
        f *= i
    return f
        

a = []
for i in range(int(input())):
    a.append(input())
letters = {}
for i in a:
    j = i[0]
    if j in letters:
        letters[j] += 1
    else:
        letters[j] = 1
m = 0
mm = True
mmm = 0

# print(letters)  
for i in letters:
    if letters[i] > 2:
        mm = True
        
        
        m = letters[i]
#         print('m', m)
        if m%2==0:
            m = m//2
            m  = (int(fact(m)/(2*fact(m-2)))) * 2
        else:
#             print('s')
            m = (int(fact(m//2)/(2*fact((m//2)-2))) + int(fact((m//2)+1)/(2*fact(((m//2)+1)-2))))
        mmm += m
#         print('mmm',m, i)
        
if(not mm):
    print(0)
else:
    print(mmm)
    
    
    


    
    