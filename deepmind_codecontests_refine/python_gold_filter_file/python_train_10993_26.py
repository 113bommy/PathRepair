a = int(input())
s = 0
i = 1
m = ["Sheldon", "Leonard", "Penny", "Rajesh", "Howard"]
if a <= 5: print(m[a-1])
else:
        while s < a:
                s = 5*(2**i - 1)
                i = i + 1
        i = i - 2
        if a <= s and a >= s - 2**i + 1:
                print("Howard")
        else:
                s = s - 2**i 
                if a <= s and a >= s - 2**i + 1:
                        print("Rajesh")
                else:
                        s = s - 2**i 
                        if a <= s and a >= s - 2**i + 1:
                                print("Penny")
                        else:
                                s = s - 2**i 
                                if a <= s and a >= s - 2**i + 1:
                                        print("Leonard")
                                else: print("Sheldon")



