def park_lighting():
    rows_columns = list(map(int,input().split()))
    cells = rows_columns[0]*rows_columns[1]
    if cells % 2 ==0:
        number_of_lights = cells/2
    else:
        number_of_lights = (cells+1)/2
    print(int(number_of_lights))
    
def main():
    for case in range(int(input())):
        park_lighting()
main()