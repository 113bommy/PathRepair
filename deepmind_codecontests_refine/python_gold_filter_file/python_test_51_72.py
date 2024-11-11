def solve(Test_cases):
    Resultant_list = []
    for i in range(Test_cases):
        # Start the code
        n = int(input())

        Resultant_list.append(-1*(n - 1))
        Resultant_list.append(n)

    return Resultant_list


Test_cases = int(input())
Result = solve(Test_cases)
for i in range(0, len(Result), 2):
    print(Result[i], Result[i + 1])
