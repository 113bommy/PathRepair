def solve(lemons, apples, pears):

    oneCompote = 1 + 2 + 4
    l = lemons/1
    a = int(apples/2)
    p = int(pears/4)

    return int(min(l,a,p) * oneCompote)

lemons = int(input())
apples = int(input())
pears = int(input())
print(solve(lemons, apples, pears))    