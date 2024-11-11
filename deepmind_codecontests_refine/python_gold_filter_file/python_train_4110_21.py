# coding: utf-8
a, b, c, d = [int(i) for i in input().split()] 
if max(3*a//10,a-a//250*c)>max(3*b//10,b-b//250*d):
    print('Misha')
elif max(3*a//10,a-a//250*c)==max(3*b//10,b-b//250*d):
    print('Tie')
else:
    print('Vasya')
