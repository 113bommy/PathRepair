p1 = list(map(int, input().split()))
p2 = list(map(int, input().split()))
p3 = list(map(int, input().split()))
p4 = list(map(int, input().split()))

t1 = [(p1[0],p2[1]), (p2[0],p1[1])]
score = [0,0]
t2 = [(p3[0],p4[1]), (p4[0],p3[1])]
t11 = t1[0]
t12 = t1[1]
t21 = t2[0]
t22 = t2[1]
# if any team of t1 wins both game, then t1 wins
# if any both team loses to any of t2, t2 wins

if t11[0] > t21[1] and t11[0] > t22[1] and t11[1] > t21[0] and t11[1] >t22[0]:
    print("Team 1")
elif t12[0] > t21[1] and t12[0] > t22[1] and t12[1] > t21[0] and t12[1] >t22[0]:
    print("Team 1")
elif ((t11[0] < t21[1] and t11[1] < t21[0] ) or ( t11[0] < t22[1] and t11[1] < t22[0])) and ((t12[0] < t21[1] and t12[1] < t21[0] ) or ( t12[0] < t22[1] and t12[1] < t22[0])):
    print("Team 2")
else:
    print("Draw")






