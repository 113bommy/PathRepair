class ehabAndAnotherConstructionProblem:
    def __init__(self, x):
        self.x = x
        self.findTwoNumbers(self.x)

    def findTwoNumbers(self, x):
        c = 1
        l = 1
        for i in range(1, x+1):
            for j in range(1, x+1):
                m = i
                n = j
                q = m//n
                if((m % n == 0) and ((m*n) > x) and (q < x)):
                    if(l == 1):
                        print(m, n)
                        l = 2
                    c = 2

        if(c == 1):
            print("-1")


x = int(input())
if(1 <= x and x <= 100):
    pass
else:
    exit()
ehabAndAnotherConstructionProblemObj = ehabAndAnotherConstructionProblem(x)
