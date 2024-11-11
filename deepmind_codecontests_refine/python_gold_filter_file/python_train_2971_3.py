a, b, c, d, e, f = map(int, input().split())
# # print(a);
# # b = int(input())
# # c = int(input())
# # d = int(input())
# # e = int(input())
# # f = int(input())
if a*c*e<b*d*f :
    print('Ron')
elif c == 0 and d != 0 :
        print('Ron')
elif a == 0 and b != 0 and d != 0:
        print('Ron')
else :
    print('Hermione')
